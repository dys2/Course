[%bs.raw {|require('./LandingMoreInfo.css')|}];

let component = ReasonReact.statelessComponent("LandingMoreInfo");

let make = _children => {
	...component,
	render: _self =>
		<div className="more-info-container">
			<h5 className="more-info-text">(ReasonReact.string("\"Most courses only get you from 0 to 80."))</h5>
			<h5 className="more-info-text">(ReasonReact.string("This course is designed to get you from 80 to 100.\""))</h5>
			<br />
			<br />
			<p className="more-info-text">
				(ReasonReact.string("We believe that education should be available and accessible to everyone.  That's why we make this content available for "))
				<strong>(ReasonReact.string("FREE"))</strong>(ReasonReact.string("."))
			</p>
			<p className="more-info-text">(ReasonReact.string("If you'd like to join the movement become a donor."))</p>
			<button onClick=(_event => ReasonReact.Router.push("/donate")) className="banner-btn">(ReasonReact.string("Donate"))</button>
		</div>
}