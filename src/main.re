let main = (port, path) => Server.start(~port, ~path, _req => ()) |> Lwt_main.run;

open Cmdliner;

type t = {
  port: int,
  path: string,
};

let portT = {
  let doc = "Port for development server to listen on";
  let docv = "NUMBER";
  Arg.(value & opt(int, 3000) & info(["p", "port"], ~docv, ~doc));
};

let pathT = {
  let doc = "The path to serve.";
  let docv = "PATH";
  let env = Arg.env_var(~doc, docv);
  Arg.(value & pos(0, string, "") & info([], ~env, ~docv, ~doc));
};

let term = {
  Term.(const(main) $ portT $ pathT);
};

let info = {
  let doc = "Serve static files.";
  let man = [
    `S(Manpage.s_bugs),
    `P("Email bug reports to <matthias_kern at posteo.net>."),
  ];

  Term.info(
    "serrve",
    ~version="v1v2v3",
    ~doc,
    ~exits=Term.default_exits,
    ~man,
  );
};

Term.exit @@ Term.eval((term, info));
