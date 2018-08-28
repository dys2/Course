[%bs.raw {|require('./CourseListCourse.css')|}];

type lesson = {
  title: string,
  description: string,
	video: string
}

type course = {
  id: int,
	name: string,
	description: string,
  image: string,
  lessons: array(lesson)
};

let component = ReasonReact.statelessComponent("CourseListCourse");

let make = (~course, _children) => {
	...component,
	render: _self =>
		<div className="course-container" onClick={_event => ReasonReact.Router.push("/course/" ++ string_of_int(course.id))}>
			<img src={course.image} alt=course.name />
			<h5>(ReasonReact.string(course.name))</h5>
			<p>(ReasonReact.string(course.description))</p>
		</div>
}