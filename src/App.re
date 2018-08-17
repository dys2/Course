[%bs.raw {|require('./App.css')|}];

[@bs.module] external logo : string = "./logo.svg";

external promiseErrorToJsObj : Js.Promise.error => Js.t('a) = "%identity";

type route =
  | Courses
  | SignUp
  | LogIn
  | Donate
  | Blog
  | Welcome
  | Landing;


type state = {
  route: route,
  auth: bool,
  signedUp: bool
};

type loginData = {
  email: string,
  password: string
}

type signUpData = SignUp.state;

type action =
  | ChangeRoute(route)
  | LogIn
  | SignUp;

type data = Js.t({
  .
  token: string
})

let component = ReasonReact.reducerComponent("App");

let logIn = (email, password, self) => {
  let user = {
    "email": email,
    "password": password
  };
  Js.Promise.(
    Axios.postData("http://localhost:5000/login", user)
    |> then_((value: Axios_types.response(data, string)) => {
      Dom.Storage.(
        localStorage |> setItem("token", value##data##token)
      )
      self.ReasonReact.send(LogIn);

      if (
        switch (ReasonReact.Router.dangerouslyGetInitialUrl().path) {
          | ["login"] => true
        }
      ) ReasonReact.Router.push("/courses");
      
      resolve();
    })
    |> catch(err => {
      resolve();
    })
    |> ignore
  )
}

let signUp = (signUpData: SignUp.state, self) => {
  let data = {
    "firstName": signUpData.firstName,
    "lastName": signUpData.lastName,
    "email": signUpData.email,
    "password": signUpData.password
  }
  Js.Promise.(
    Axios.postData("http://localhost:5000/create_user", data)
    |> then_(value => {
      self.ReasonReact.send(SignUp);
      resolve()
    })
    |> catch(err => {
      resolve();
    })
    |> ignore
  )
}

let make = (_children) => {
  ...component,
  initialState: () => {
    route: Landing,
    auth: false,
    signedUp: false
  },
  reducer: (action, state) =>
    switch (action) {
      | ChangeRoute(route) => ReasonReact.Update({...state, route})
      | LogIn => ReasonReact.Update({...state, auth: true})
      | SignUp => ReasonReact.Update({...state, signedUp: true})
    },
  didMount: self => {
    let watcherID = ReasonReact.Router.watchUrl(url => {
      switch (url.path) {
        | ["courses"] => self.send(ChangeRoute(Courses))
        | ["signup"] => self.send(ChangeRoute(SignUp))
        | ["login"] => self.send(ChangeRoute(LogIn))
        | ["donate"] => self.send(ChangeRoute(Donate))
        | ["blog"] => self.send(ChangeRoute(Blog))
        | ["welcome"] => self.send(ChangeRoute(Welcome))
        | [] => self.send(ChangeRoute(Landing))
        | _ => self.send(ChangeRoute(Landing))
      }
    });
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherID));
  },
  render: self =>
    <div className="App">
      (
        switch (self.state.route) {
          | Landing => <Landing />
          | Courses => <Courses />
          | SignUp => <SignUp signedUp=self.state.signedUp signUp=(signUpData => signUp(signUpData, self)) />
          | LogIn => <LogIn logIn=((email, password) => logIn(email, password, self)) />
          | Blog => <Blog />
          | Welcome => <Welcome auth=self.state.auth logIn=((email, password) => logIn(email, password, self)) />
          | Donate => <Donate />
        }
      )
    </div>,
};