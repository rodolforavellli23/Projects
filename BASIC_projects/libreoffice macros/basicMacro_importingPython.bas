REM  *****  BASIC  *****

REM function Greeting(sName As String) As String
REM		Greeting = "Hello " & sName & "!"
REM end function


function Greeting(sName As String) As String
	pyFile   = "myPythonScripts.py"
	pyFunc   = "Greeting"
	pyParams = Array(sName)
	
	' Get script provider through document context
	ScriptProvider = CreateUnoService("com.sun.star.script.provider.MasterScriptProvider")
	
	' Construct script URI
	scriptURL = "vnd.sun.star.script:" & pyFile & "$" & pyFunc & "?language=Python&location=user"
	pyScript  = ScriptProvider.getScript(scriptURL)
	Greeting  = pyScript.invoke(pyParams, Array(), Array())
end function
