[%bs.raw {|require('./App.css')|}];

[@bs.module] external logo : string = "./logo.svg";

external promiseErrorToJsObj : Js.Promise.error => Js.t('a) = "%identity";

type route =
  | Course(string)
  | Courses
  | Create
  | SignUp
  | Lesson(int, int)
  | LogIn
  | Donate
  | Blog
  | Welcome
  | Landing;


type state = {
  route: route,
  auth:  bool,
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


let checkAuth = (self) =>
  Js.Promise.(
    API.fetch(~endpoint="check_auth", ~body="", ~method=Get)
    	|> then_(_res => resolve())
			|> catch(_err => resolve())
			|> ignore
  );
  

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
    
    let token = Dom.Storage.(localStorage |> getItem("token"));
    switch(token) {
      | None => Js.log("No Token Saved")
      | Some(avs) => self.send(LogIn)
    }
    let watcherID = ReasonReact.Router.watchUrl(url => {
      switch (url.path) {
        | ["courses"] => self.send(ChangeRoute(Courses))
        | ["course", courseId, "lesson", index] => self.send(ChangeRoute(Lesson(int_of_string(courseId), int_of_string(index))))
        | ["course", id] => self.send(ChangeRoute(Course(id)))
        | ["create"] => self.send(ChangeRoute(Create))
        | ["signup"] => self.send(ChangeRoute(SignUp))
        | ["login"] => self.send(ChangeRoute(LogIn))
        | ["donate"] => self.send(ChangeRoute(Donate))
        | ["blog"] => self.send(ChangeRoute(Blog))
        | ["welcome"] => self.send(ChangeRoute(Welcome))
        | [] => self.send(ChangeRoute(Landing))
        | _ => Js.log(url)
      }
    });
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherID));
  },
  render: self =>
    <div className="App">
      (
        switch (self.state.route) {
          | Create => <Create />
          | Landing => <Landing />
          | Course(id) => <Course id=int_of_string(id) />
          | Courses => <Courses />
          | SignUp => <SignUp signedUp=self.state.signedUp signUp=(signUpData => signUp(signUpData, self)) />
          | Lesson(courseId, index) => <Lesson courseId=courseId index=index />
          | LogIn => <LogIn logIn=((email, password) => logIn(email, password, self)) />
          | Blog => <Blog />
          | Welcome => <Welcome auth=self.state.auth logIn=((email, password) => logIn(email, password, self)) />
          | Donate => <Donate />
        }
      )
    </div>,
};