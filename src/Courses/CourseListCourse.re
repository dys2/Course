[%bs.raw {|require('./CourseListCourse.css')|}];

type course = {
	name: string,
	description: string,
	image: string
};

let component = ReasonReact.statelessComponent("CourseListCourse");


let make = (~course, _children) => {
	...component,
	render: _self =>
		<div className="course-container">
			<img src={course.image} alt=course.name />
			<h5>(ReasonReact.string(course.name))</h5>
			<p>(ReasonReact.string(course.description))</p>
		</div>
}