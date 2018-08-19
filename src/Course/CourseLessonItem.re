[%bs.raw {|require('./CourseLessonItem.css')|}]


let component = ReasonReact.statelessComponent("CouseLessonItem");


let make = (~lesson: CourseListCourse.lesson, _children) => {
  ...component,
  render: _self =>
    <li className="course-lesson-item">
      <p>(ReasonReact.string(lesson.title))</p>
    </li>
}