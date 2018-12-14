/* copied from https://github.com/anmonteiro/reason-graphql-fullstack */

module C = Cohttp_lwt_unix;

module CServer = Cohttp_lwt_unix.Server;
let serveStatic = (base, path) => {
  let fname = Filename.concat(base, path);
  if (Sys.file_exists(fname)) {
    if (Sys.is_directory(fname)) {
      if (Sys.file_exists(Filename.concat(fname, "index.html"))) {
        CServer.respond_file(
          ~fname=Filename.concat(fname, "index.html"),
          (),
        );
      } else {
        C.Server.respond_string(~status=`Not_found, ~body="", ());
      };
    } else {
      CServer.respond_file(~fname, ());
    };
  } else if (Sys.file_exists(fname ++ ".html")) {
    CServer.respond_file(~fname=fname ++ ".html", ());
  } else {
    C.Server.respond_string(~status=`Not_found, ~body="", ());
  };
};

let make_callback = (base_path, _context, _conn, req: Cohttp.Request.t, body) => {
  Printf.printf("Req: %s\n%!", req.resource);
  let req_path = Cohttp.Request.uri(req) |> Uri.path;
  let path_parts = Str.(split(regexp("/"), req_path));
  switch (req.meth, path_parts) {
  | (`GET, _) => serveStatic(base_path, req_path)
  | _ => C.Server.respond_string(~status=`Not_found, ~body="", ())
  };
};

let start = (~port, ~path, ctx) => {
  let callback = make_callback(path, ctx);
  C.Server.create(~mode=`TCP(`Port(port)), C.Server.make(~callback, ()));
};
