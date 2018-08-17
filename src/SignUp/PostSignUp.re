let component = ReasonReact.statelessComponent("PostSignUp");


let divStyle = ReactDOMRe.Style.make(
	~display="flex",
	~flexDirection="column",
	~height="100vh",
	~justifyContent="center",
	()
);

let make = (_children) => {
	...component,
	render: _self =>
		<div style=divStyle >
			<h1>(ReasonReact.string("Confirm your email to continue"))</h1>
			<p><strong>(ReasonReact.string("Click Here"))</strong>(ReasonReact.string(" if you haven't received it"))</p>
		</div>
}