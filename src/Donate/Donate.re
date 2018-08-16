[%bs.raw {|require('./Donate.css')|}];

type state = {
	level: int,
	monthly: bool
};

type action =
	| ChangeLevel(int, bool);

let component = ReasonReact.reducerComponent("Donate");



let make = _children => {
	...component,
	initialState: () => { level: 0, monthly: false },
	reducer: (action, state) =>
		switch(action) {
			| ChangeLevel(level, monthly) => ReasonReact.Update({...state, level: level, monthly: monthly})
		},
	render: self =>
		<div className="donate-container">
			<LandingHeader />
			<h3>(ReasonReact.string("Join The Education Revolution"))</h3>
			<p>(ReasonReact.string("Members are instantly enrolled in raffles for select giveaways.  In addition to other offers based on donation level."))</p>
			<div className="donation-box-container" >
				<div className="donation-box">
					<h5>(ReasonReact.string("Monthly Membership"))</h5>
					<div className="donation-selections">
						(
							ReasonReact.array(
								Array.map(
									amount =>
										<DonateSelectBox amount=amount changeLevel=(level => self.send(ChangeLevel(level, true))) />,
									[|5, 10, 20|]
								)
							)
						)
					</div>
				</div>
				<div className="donation-box">
					<h5>(ReasonReact.string("One Time"))</h5>
					<div className="donation-selections" >
						(
							ReasonReact.array(
								Array.map(
									amount =>
										<DonateSelectBox amount=amount changeLevel=(level => self.send(ChangeLevel(level, false))) />,
									[|10, 25, 50|]
								)
							)
						)
					</div>
				</div>
			</div>
			<WhyDonate level={self.state.level} monthly={self.state.monthly} />
		</div>
}