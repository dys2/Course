[@bs.module "./ApolloProviderJS"] external apolloProvider : ReasonReact.reactClass = "default";


let make = (children) => {
	ReasonReact.wrapJsForReason(
		~reactClass=apolloProvider,
		~props=Js.Obj.empty(),
		children
	)
}