[%bs.raw {|require('./DonateSelectBox.css')|}];

let component = ReasonReact.statelessComponent("DonateSelectBox");

let make = (~amount, ~changeLevel, _children) => {
	...component,
	render: _self =>
		<div onMouseEnter={_event => changeLevel(amount)} onMouseLeave={_event => changeLevel(0)} className="donate-select-box">
			<p>(ReasonReact.string("$" ++ string_of_int(amount)))</p>
		</div>
}