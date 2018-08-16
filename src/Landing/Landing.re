let component = ReasonReact.statelessComponent("Landing");

let make = (_children) => {
	...component,
	render: _self =>
		<div>
			<LandingBanner message="Cutting Edge Curriculum for Cutting Edge Developers" showCoursesBtn=true />
			<LandingMoreInfo />
		</div>
}