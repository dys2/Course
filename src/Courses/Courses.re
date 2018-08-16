let component = ReasonReact.statelessComponent("Courses");

let make = _children => {
	...component,
	render: _self =>
		<div>
			<LandingBanner />
			<CoursesList />
		</div>
}