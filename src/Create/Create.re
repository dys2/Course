type page =
  | Default
  | NewCourse;

type state = {
  current: page
}


type action =
  | UpdateCurrent(page);


let component = ReasonReact.reducerComponent("Create");

let make = _children => {
  ...component,
  initialState: () => {
    current: Default
  },
  reducer: (action, state) =>
    switch (action) {
      | UpdateCurrent(newCurrent) => ReasonReact.Update({...state, current: newCurrent})
    },
	render: self =>
		<div style={ReactDOMRe.Style.make(~backgroundColor="#333", ())}>
      <h1
        style={ReactDOMRe.Style.make(
          ~color="#FFF",
          ~margin="0",  
          ()
        )}
      >
        (ReasonReact.string("Creation Station"))
      </h1>
      <CreateOptions
        goToNewCourse={_event => self.send(UpdateCurrent(NewCourse))}
      />
      (
        switch self.state.current {
          | Default => <div></div>
          | NewCourse => <NewCourse />
        }
      )
		</div>
}