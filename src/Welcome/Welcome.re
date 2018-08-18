type action =
	| Verify;

type state = {
	verified: bool
};

let component = ReasonReact.reducerComponent("Welcome");


let divStyle = ReactDOMRe.Style.make(
	~display="flex",
	~flexDirection="column",
	~height="100vh",
	~justifyContent="center",
	()
);




let make = (~auth, ~logIn, _children) => {
	...component,
	initialState: () => {verified: false},
	reducer: (action, _state) =>
		switch(action) {
			| Verify => ReasonReact.Update({verified: true})
		},
	didMount: self => {
		Js.Promise.(
			Fetch.fetchWithInit(
				"http://localhost:5000/verify_user",
				Fetch.RequestInit.make(
					~method_=Put,
					~body=Fetch.BodyInit.make(""),
					~headers=Fetch.HeadersInit.make({
						"Content-Type": "application/json",
						"Authorization": Dom.Storage.(
							localStorage |> getItem("token")
						)
					}),
					()
				)
			)
			|> then_(_res => {
				self.send(Verify)
				resolve()
			})
			|> catch(_err => resolve())
			|> ignore
		)
		
	},
	render: self =>
		!auth ?
			<LogIn logIn=logIn /> :
			<div style=divStyle >
				<h1>(ReasonReact.string("Thanks for verifying"))</h1>
				(
					self.state.verified ?
						<p>(ReasonReact.string("Continue To Content"))</p>:
						ReasonReact.null
				)
			</div>
}