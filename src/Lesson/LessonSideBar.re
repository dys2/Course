[%bs.raw {|require('./LessonSideBar.css')|}];

type action =
	| ToggleOpen;

type state = {
	show: bool
}

let component = ReasonReact.reducerComponent("LessonSideBar");

let make = (~course: CourseListCourse.course, _children) => {
	...component,
	initialState: () => { show: false },
	reducer: (action, state) =>
		switch(action) {
			| ToggleOpen => ReasonReact.Update({ show: !state.show })
		},
	render: self =>
		<div className={"lesson-sidebar-container " ++ (self.state.show ? "show-sidebar" : "hide-sidebar")} >
			<h1>(ReasonReact.string(course.name))</h1>
			<ul>
				(ReasonReact.array(
					Array.mapi(
						(index, lesson: CourseListCourse.lesson) => 
							<li onClick=(_event => ReasonReact.Router.push("/course/" ++ string_of_int(course.id) ++ "/lesson/" ++ string_of_int(index))) key={lesson.title}>(ReasonReact.string(lesson.title))</li>,
						course.lessons
					)
				))
			</ul>
		</div>
}