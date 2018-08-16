[%bs.raw {|require('./App.css')|}];

[@bs.module] external logo : string = "./logo.svg";

type route =
  | Courses
  | SignUp
  | Landing;

type state = {
	route: route
};

type action =
  | ChangeRoute(route);


let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,
  initialState: () => { route: Landing },
  reducer: (action, _state) =>
    switch (action) {
      | ChangeRoute(route) => ReasonReact.Update({route: route})
    },
  didMount: self => {
    let watcherID = ReasonReact.Router.watchUrl(url => {
      switch (url.path) {
        | ["courses"] => self.send(ChangeRoute(Courses))
        | ["signup"] => self.send(ChangeRoute(SignUp))
        | [] => self.send(ChangeRoute(Landing))
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
          | SignUp => <SignUp />
        }
      )
    </div>,
};