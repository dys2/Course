[%bs.raw {|require('../SignUp/SignUp.css')|}];

[@bs.module] external logo : string = "../logo-grey.svg";


type state = {
	email: string,
	password: string
};

type action =
	| HandleEmail(string)
	| HandlePassword(string);

let component = ReasonReact.reducerComponent("LogIn");

let make = (~logIn, _children) => {
	let submit = (event, self) => {
		ReactEvent.Form.preventDefault(event);
		logIn(self.ReasonReact.state.email, self.ReasonReact.state.password)
	};
	{
		...component,
		initialState: () => {email: "", password: ""},
		reducer: (action, state) =>
			switch (action) {
				| HandleEmail(value) => ReasonReact.Update({ ...state, email: value })
				| HandlePassword(value) => ReasonReact.Update({ ...state, password: value });
			},
		render: self =>
			<div className="sign-up-container">
				<LandingHeader />
				<form className="sign-up-form" onSubmit=(self.handle(submit))>
					<h1>(ReasonReact.string("Log In Gangsta"))</h1>
					<input type_="email" placeholder="Email" onChange=(event => self.send(HandleEmail(ReactEvent.Form.target(event)##value))) />
					<input type_="password" placeholder="Password" onChange=(event => self.send(HandlePassword(ReactEvent.Form.target(event)##value))) />
					<input className="submit-btn" type_="submit" />
				</form>
				<img src={logo} alt="logo" />
			</div>
	}
}