let component = ReasonReact.statelessComponent("Blog");

let make = _children => {
	...component,
	render: _self =>
		<div>
			<h1>(ReasonReact.string("Blog"))</h1>
			<p>(ReasonReact.string("Coming Soon.."))</p>
			<button onClick={_event => ReasonReact.Router.push("/")}>(ReasonReact.string("Return"))</button>
		</div>
}