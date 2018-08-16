let component = ReasonReact.statelessComponent("Landing");

let make = (_children) => {
	...component,
	render: _self =>
		<div>
			<LandingBanner />
			<LandingMoreInfo />
		</div>
}