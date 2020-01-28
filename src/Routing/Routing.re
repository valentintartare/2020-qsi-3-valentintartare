[@bs.val] external document: Js.t({..}) = "document";

let makeContainer = text => {
  let container = document##createElement("div");
  container##className #= "container";

  let title = document##createElement("div");
  title##className #= "containerTitle";
  title##innerText #= text;

  let content = document##createElement("div");
  content##className #= "containerContent";

  let () = container##appendChild(title);
  let () = container##appendChild(content);
  let () = document##body##appendChild(container);

  content;
};

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  switch (url.path) {
    | ["greetings"] =>  ReactDOMRe.render(<Greeting />, makeContainer("Atomic Greeting"));
    | ["blinking"] => ReactDOMRe.render(
                        <BlinkingGreeting> {React.string("Hello!")} </BlinkingGreeting>,
                        makeContainer("Blinking Greeting"));
    | ["reducer"] => ReactDOMRe.render(
                    <ReducerFromReactJSDocs />,
                    makeContainer("Reducer From ReactJS Docs"));
    | ["fetchedDog"] => ReactDOMRe.render(
                        <FetchedDogPictures />,
                        makeContainer("Fetched Dog Pictures"));

    | ["randomDog"] => ReactDOMRe.render(<FetchRandomDog />, makeContainer("1 random Dog"));
    };
    <>
    </>
}