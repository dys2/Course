[@bs.module] external reactSVG : string = "./react.svg";
[%bs.raw {|require('./LandingBanner.css')|}];

let component = ReasonReact.statelessComponent("LandingBanner");


let divStyle = ReactDOMRe.Style.make(
	~height="100vh",
	~width="100vw",
	()
);

let innerDivStyle = ReactDOMRe.Style.make(
	~height="calc(100vh - 80px)",
	~width="calc(100% - 80px)",
	~paddingTop="80px",
	~marginRight="40px",
	~marginLeft="40px",
	~display="flex",
	~flexDirection="column",
	~alignItems="center",
	~borderBottom="solid 1px #444",
	()
);


let make = _children => {
	...component,
	render: _self =>
		<div style=(divStyle)>
			<div style=(innerDivStyle)>
				<LandingHeader />
				<img className="react-img" src={reactSVG} alt="react" />
				<h3 className="banner-text">(ReasonReact.string("Cutting Edge Curriculum for Cutting Edge Developers"))</h3>
				<button className="banner-btn" onClick=(_event => ReasonReact.Router.push("courses"))>(ReasonReact.string("COURSES"))</button>
			</div>
		</div>
}

