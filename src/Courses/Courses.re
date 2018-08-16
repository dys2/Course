let component = ReasonReact.statelessComponent("Courses");

let make = _children => {
	...component,
	render: _self =>
		<div>
			<LandingBanner message="Check Out Courses Below" showCoursesBtn=false />
			<CoursesList />
		</div>
}