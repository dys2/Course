[%bs.raw {|require('./WhyDonate.css')|}];

let component = ReasonReact.statelessComponent("WhyDonate");

let slack = "Access to slack channel with content creators";
let meeting = "Monthly one hour meeting with content creators";
let raffle = "Enrollment into raffle giveaways";

let benefits: (bool, int) => array(string) =
	(monthly, level) =>
		monthly ?
			switch (level) {
				| 5 => [|raffle, slack|]
				| 10 => [|raffle, slack|]
				| 20 => [|raffle, slack, meeting|]
			} : switch (level) {
				| 10 => [|raffle|]
				| 25 => [|raffle|]
				| 50 => [|raffle|]
			};

let make = (~level, ~monthly, _children) => {
	...component,
	render: _self =>
		<div className="why-donate">
			(
				level > 0 ?
					<>
						<h5>
							(ReasonReact.string(
								"The " ++
								string_of_int(level) ++ 
								" dollar " ++
								(monthly ? "monthly " : "") ++
								"level comes with the following benefits:"
							))
						</h5>
						<ul>
							(
								ReasonReact.array(
									Array.map(
										benefit => <li>(ReasonReact.string(benefit))</li>,
										benefits(monthly, level)
									)
								)
							)
						</ul>
					</> : <h5>(ReasonReact.string("Hover over a selection to see how we appreciate our members"))</h5>
			)
		</div>
}

