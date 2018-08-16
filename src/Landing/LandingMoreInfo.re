[%bs.raw {|require('./LandingMoreInfo.css')|}];

let component = ReasonReact.statelessComponent("LandingMoreInfo");

let make = _children => {
	...component,
	render: _self =>
		<div className="more-info-container">
			<h5 className="more-info-text">(ReasonReact.string("\"Most courses only get you from 0 to 80."))</h5>
			<h5 className="more-info-text">(ReasonReact.string("This course is designed to get you from 80 to 100.\""))</h5>
		</div>
}