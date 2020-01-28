open ReasonUrql;
/* Be sure to open the Hooks module to bring necessary types into scope. */
open Hooks;

/* Create a module with your GraphQL query. */
module DogsQuery = [%graphql
  {|
  {
  user(login: "valentintartare") {
    id
    avatarUrl
    following(first: 10) {
      edges {
        node {
          id
        }
      }
    }
    followers(first: 10) {
      edges {
        node {
          id
        }
      }
    }
    status {
      id
    }
  }
}
|}
];
}
