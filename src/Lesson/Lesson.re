[%bs.raw {|require('./Lesson.css')|}];

type state = {
	course: CourseListCourse.course,
	lesson: CourseListCourse.lesson
}

let component = ReasonReact.reducerComponent("Lesson");


let make = (~courseId, ~index, _children) => {
	...component,
	initialState: () => {course: Array.get(CoursesList.courses, courseId), lesson: Array.get(CoursesList.courses, courseId).lessons[index]},
	willReceiveProps: self =>{course: Array.get(CoursesList.courses, courseId), lesson: Array.get(CoursesList.courses, courseId).lessons[index]},
  reducer: ((), _) => ReasonReact.NoUpdate,
	render: self =>
		<div className="lesson-page">
			<LandingHeader />
			<div className="lesson-container" >
				<LessonSideBar course=self.state.course />
				<LessonContents lesson=self.state.lesson />
			</div>
		</div>
}