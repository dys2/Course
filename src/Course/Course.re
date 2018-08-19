[%bs.raw {|require('./Course.css')|}]

type state = {
  course: CourseListCourse.course
}

let component = ReasonReact.reducerComponent("Course");


let make = (~id, _children) => {
  ...component,
  initialState: () => {course: Array.get(CoursesList.courses, id)},
  reducer: ((), _) => ReasonReact.NoUpdate,
  render: self =>
    <div className="course-page">
      <LandingHeader />
      <div className="course-page-header-container">
        <div className="course-page-header-info">
          <h1>(ReasonReact.string(self.state.course.name))</h1>
          <h5>(ReasonReact.string(self.state.course.description))</h5>
          <div className="course-page-progress">
            <div style={ReactDOMRe.Style.make(~width="calc(100% - 240px)", ())}><ProgressBar progress="10"/></div>
            <button className="course-shadow">(ReasonReact.string("CONTINUE"))</button>
          </div>
        </div>
        <div className="course-page-header-image">
          <img src={self.state.course.image} alt={self.state.course.name}/>
        </div>
      </div>
        <h4>(ReasonReact.string("Lessons"))</h4>
        <ul>
          (ReasonReact.array(
            Array.map(
              lesson => <CourseLessonItem lesson=lesson />,
              self.state.course.lessons
            )
          ))
        </ul>

    </div>
}