[@bs.module] external plyrVideo: ReasonReact.reactClass = "./PlyrVideoJS";

[@bs.deriving abstract]
type jsProps = {
	videoUrl: string,
	poster: string
};

let make = (~videoUrl: string, children) =>
	ReasonReact.wrapJsForReason(
		~reactClass=plyrVideo,
		~props=jsProps(
			~videoUrl=videoUrl,
			~poster="https://camo.githubusercontent.com/85c414a82d38ed8570c1411b279c0be870b3a7cc/68747470733a2f2f63646e2e706c79722e696f2f7374617469632f64656d6f2f73637265656e73686f742e706e673f763d33"
		),
		children
	);