[%bs.raw {|require('./SignUp.css')|}];

[@bs.module] external logo : string = "../logo.svg";


type state = {
	firstName: string,
	lastName: string,
	email: string,
	password: string
};

type action =
	| HandleFirstName(string)
	| HandleLastName(string)
	| HandleEmail(string)
	| HandlePassword(string)
	| HandleSubmit;

let component = ReasonReact.reducerComponent("SignUp");

let make = _children => {
	...component,
	initialState: () => {firstName: "", lastName: "", email: "", password: ""},
	reducer: (action, state) =>
		switch (action) {
			| HandleFirstName(value) => ReasonReact.Update({ ...state, firstName: value })
			| HandleLastName(value) => ReasonReact.Update({ ...state, lastName: value })
			| HandleEmail(value) => ReasonReact.Update({ ...state, email: value })
			| HandlePassword(value) => ReasonReact.Update({ ...state, password: value });
		},
	render: self =>
		<div className="sign-up-container">
			<LandingHeader />
			<form className="sign-up-form">
				<h1>(ReasonReact.string("Sign Up Gangsta"))</h1>
				<input placeholder="First Name" onChange=(event => self.send(HandleFirstName(ReactEvent.Form.target(event)##value))) />
				<input placeholder="Last Name" onChange=(event => self.send(HandleLastName(ReactEvent.Form.target(event)##value))) />
				<input type_="email" placeholder="Email" onChange=(event => self.send(HandleEmail(ReactEvent.Form.target(event)##value))) />
				<input type_="password" placeholder="Password" onChange=(event => self.send(HandlePassword(ReactEvent.Form.target(event)##value))) />
				<input className="submit-btn" type_="submit" />
			</form>
			<img src={logo} alt="logo" />
		</div>
}