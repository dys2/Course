[%bs.raw {|require('./LandingHeader.css')|}];

[@bs.module] external logo : string = "../logo.svg";

let component = ReasonReact.statelessComponent("LandingHeader");

let items: array(string) = [|"Courses", "Blog", "Log In"|];

let make = _children => {
	...component,
	render: _self =>
		<div className="landing-header-container" >
			<img onClick=(_event => ReasonReact.Router.push("/")) src={logo} alt="logo" />
			<div>
				(ReasonReact.array(
						Array.map(
						item => <p className="landing-header-item" onClick=(_event => ReasonReact.Router.push(String.lowercase(item))) >(ReasonReact.string(item))</p>,
						items
					)
				))
			</div>
		</div>
}