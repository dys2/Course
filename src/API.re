let fetch = (~endpoint, ~body, ~method) =>
  Fetch.fetchWithInit(
    "http://localhost:5000/" ++ endpoint,
    Fetch.RequestInit.make(
      ~method_=method,
      ~body=Fetch.BodyInit.make(body),
      ~headers=Fetch.HeadersInit.make({
        "Content-Type": "application/json",
        "Authorization": Dom.Storage.(
          localStorage |> getItem("token")
        )
      }),
      ()
    )
  );
