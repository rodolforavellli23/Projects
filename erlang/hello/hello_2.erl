#!/usr/bin/escript

-module(hello).

-export([main/1]).

main(_Args) ->

	Message = ["Hello World! ", "From Erlang/OTP v."],

	io:format(
	  "~n~*..*s~s~s~*..*s~n~n",
	  [
	   5, $*, " ",
	   Message,
	   erlang:system_info(otp_release),
	   -5, $*, " "
	  ]
	).

%% When using the ~*..* interpolation sigyl, you may define a custom padding,
%% where: [ width_int, $fill_char, "string_to_pad" ]
