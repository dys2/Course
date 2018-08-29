[%bs.raw {|require('./NewCourse.css')|}];


let component = ReasonReact.statelessComponent("NewCourse");


let make = _children => {
  ...component,
  render: _self =>
    <div className="new-course">
      <h1>(ReasonReact.string("New Course"))</h1>
    <form className="new-course-basic">
      <input placeholder="Title" required={true} />
      <textarea placeholder="Description" required={true} />
      <input id="new-course-file" type_="file" name="file" accept="image/*" />
      <label htmlFor="new-course-file">(ReasonReact.string("Choose a file"))</label>
      <input type_="submit" />
    </form>
    </div>
}