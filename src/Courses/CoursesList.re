[@bs.module] external reactSVG : string = "./react-1.svg";
[@bs.module] external reasonReactJPG : string = "./reasonreact.jpg";
[@bs.module] external reduxSVG : string = "./redux.svg";
[%bs.raw {|require('./CoursesList.css')|}];

let component = ReasonReact.statelessComponent("CoursesList");


let courses: array(CourseListCourse.course) = [|
	{
    id: 0,
		name: "Universal React",
		description: "Typically react applications are rendered on the client but there are benefits to rendering your application on the server.  Universal Rendering describes an application whose initial render comes from the server but subsequent renders occur on the client.",
    image: reactSVG,
    lessons: [|
      {
        title: "First Lesson",
        description: "This is the first lesson.  It teaches the basics of everything.",
        video: "http://techslides.com/demos/sample-videos/small.mp4"
      },
      {
        title: "Second Lesson",
        description: "This is the first lesson.  It teaches the basics of everything.",
        video: "http://techslides.com/demos/sample-videos/small.mp4"
      }
    |]
	},
	{
    id: 1,
		name: "Reason React",
		description: "Use React how it was meant to be used with ReasonReact.  You can now bring ReasonML; a fun, flexible, type safe language to your React projects.",
    image: reasonReactJPG,
    lessons: [|
      {
        title: "First Lesson",
        description: "This is the first lesson.  It teaches the basics of everything.",
        video: "http://techslides.com/demos/sample-videos/small.mp4"
      },
      {
        title: "Second Lesson",
        description: "This is the first lesson.  It teaches the basics of everything.",
        video: "http://techslides.com/demos/sample-videos/small.mp4"
      }
    |]
	},
	{
    id: 2,
		name: "React-Redux From Scratch",
		description: "React Redux has exploded onto the scene, bringing a one way flow of data to React projects.  In this course we take a closer look at React Redux and whats happening underneath the hood",
    image: reduxSVG,
    lessons: [|
      {
        title: "First Lesson",
        description: "This is the first lesson.  It teaches the basics of everything.",
        video: "http://techslides.com/demos/sample-videos/small.mp4"
      },
      {
        title: "Second Lesson",
        description: "This is the first lesson.  It teaches the basics of everything.",
        video: "http://techslides.com/demos/sample-videos/small.mp4"
      }
    |]
	}
|];

let make = _children => {
	...component,
	render: _self =>
		<div className="courses-list-container">
			<h5 className="courses-list-text">(ReasonReact.string("Courses"))</h5>
			(
				ReasonReact.array(
					Array.map(
						course => <CourseListCourse course=(course) />,
						courses
					)
				)
			)
		</div>
}