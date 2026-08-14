#!/usr/bin/escript

%% List sequences in erlang are 
%% end inclusive

%% Program name
-module(hello).

%% Functions to be used, and their nº args
-export([main/1, pad/2]).

%% Function specification
-spec pad(integer(), string()) -> binary().
pad(X, Y) ->
	List = [Y || _ <- lists:seq(1, X)],
	iolist_to_binary(List).

%% Program entry point
main(_Args) ->

	%% Pad definition
	Pad_0     = pad(1, " "),
	Pad_star  = pad(4, "*"),
	Pad_start = [Pad_star, Pad_0],
	Pad_end   = [Pad_0, Pad_star],

	%% Fetching the Erlang Version
	Vers = 
	erlang:system_info(otp_release),

	%% Message to send
	Message = [
		    Pad_start,
		    "Hello World! ",
		    "From Erlang/OTP",
		    " v.",
		    Vers, 
		    Pad_end
		  ],

	%% Terminal Output
	io:format("~n~s~n~n", [Message]).
