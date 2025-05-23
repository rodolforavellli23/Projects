REM  *****  BASIC  *****

REM function Greeting(sName As String) As String
REM		Greeting = "Hello " & sName & "!"
REM end function


function Greeting(sName As String) As String
	pyFile   = "myPythonScripts.py"
	pyFunc   = "Greeting"
	pyParams = Array(sName)
	
	' Get script provider through document context
	'ctx = GetDefaultContext()
    'spf = ctx.getValueByName("/singletons/com.sun.star.script.provider.theMasterScriptProviderFactory")	
	'ScriptProvider = spf.createScriptProvider("")
	ScriptProvider = CreateUnoService("com.sun.star.script.provider.MasterScriptProvider")
	
	' Construct script URI
	scriptURL = "vnd.sun.star.script:" & pyFile & "$" & pyFunc & "?language=Python&location=user"
	pyScript  = ScriptProvider.getScript(scriptURL)
	Greeting  = pyScript.invoke(pyParams, Array(), Array())
end function
