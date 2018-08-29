[%bs.raw {|require('./LessonContents.css')|}];


let component = ReasonReact.statelessComponent("LessonContents");

let make = (~lesson: CourseListCourse.lesson, _children) => {
	...component,
	render: _self =>
    <div className="lesson-contents-container">
      <h2>(ReasonReact.string(lesson.title))</h2>
         <PlyrVideo videoUrl={lesson.video} /> 
      <p>(ReasonReact.string(lesson.description))</p>
    </div>
}