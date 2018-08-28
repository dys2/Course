[%bs.raw {|require('./CourseLessonItem.css')|}]


let component = ReasonReact.statelessComponent("CouseLessonItem");


let make = (~lesson: CourseListCourse.lesson, ~index: int, ~courseId: int, _children) => {
  ...component,
  render: _self =>
    <li className="course-lesson-item" onClick=(_event => ReasonReact.Router.push("/course/" ++ string_of_int(courseId) ++ "/lesson/" ++ string_of_int(index)))>
      <p>(ReasonReact.string(lesson.title))</p>
    </li>
}