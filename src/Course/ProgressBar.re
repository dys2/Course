let component = ReasonReact.statelessComponent("ProgressBar");


let outerDivStyle = ReactDOMRe.Style.make(
  ~width="100%",
  ~backgroundColor="#FFF",
  ~border="solid 1px #333",
  ~borderRadius="12px",
  ~overflow="hidden",
  ()
);


let make = (~progress, _children) => {
  ...component,
  render: _self =>
    <div className="progress-total" style={outerDivStyle}>
      <div
        className="current-progress"
        style={ReactDOMRe.Style.make(
          ~width=progress++"%",
          ~backgroundColor="#555",
          ~height="100%",
          ~display="flex",
          ~alignItems="center",
          ~justifyContent="center",
          ()
        )}
      >
        (ReasonReact.string(progress))
      </div>
    </div>
}