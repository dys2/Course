[%bs.raw {|require('./CreateOptions.css')|}];


let component = ReasonReact.statelessComponent("CreateOptions");


let make = (~goToNewCourse, _children) => {
  ...component,
  render: self =>
    <ul className="create-options">
      <li>(ReasonReact.string("My Courses"))</li>
      <li onClick=(goToNewCourse)>(ReasonReact.string("New Course"))</li>
    </ul>
}