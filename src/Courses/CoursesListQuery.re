[@bs.module "./CoursesListQueryJS"] external coursesList : ReasonReact.reactClass = "default";

let make = _children => 
	ReasonReact.wrapJsForReason(
		~reactClass=coursesList,
		~props=Js.Obj.empty(),
		[||]
	);