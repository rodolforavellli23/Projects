program pascalsyntax;

{This is a test program}

{* This shows some
   common elements of
   Pascal syntax *}

// Variables declaration
var
  sum: integer;

  procedure Goodbye;
  begin
    writeln('Press ''enter'' to end the program');
    readln;
  end;

  procedure Add(num1,num2: integer);
  begin
    writeln(num1 + num2);
  end;

  function Multiply(num1, num2: integer): integer;
  var
    num: integer;
  begin
    num := num1 * num2;
    Result := num;
  end;
begin
  Add(5, 10);
  sum := Multiply(5, 10);
  Write('5 * 10 = ');
  writeln(sum);
  if sum = 50 then
    writeln('You win a special prize!');
  Goodbye;
end.
