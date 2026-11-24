<html>
	<head>
		<title> Conexão MySQL </title>
		<meta http-equiv="content-type" content="text/html;charset=utf-8" />
	</head>
	<body>
		<?php						
			function mysqli_result($res, $row, $field=0) {
			$res->data_seek($row);
			$datarow = $res->fetch_array();
			return $datarow[$field];}
		
			$conexao = mysqli_connect("localhost", "root", "") or die("Falha ao conectar.");
			
			mysqli_select_db($conexao, "alunos") or die("Falha ao conectar ao banco.");
			
			$query = "SELECT * FROM alunos";
			
			$resultado = mysqli_query($conexao, $query);
			
			$nLinhas = mysqli_num_rows($resultado);
			
			for($i=0; $i<$nLinhas; $i++){
				echo "<b>".mysqli_result($resultado, $i, "nome")."</b>"."<br>&nbsp&nbsp&nbsp&nbsp&nbsp".
					"\tId: ".mysqli_result($resultado, $i, "ID").
					"\tLogin: ".mysqli_result($resultado, $i, "login").
					"\tSenha: ".mysqli_result($resultado, $i, "senha").
					"\tIdade: ".mysqli_result($resultado, $i, "idade").
					"\tCidade: ".mysqli_result($resultado, $i, "cidade").
					"\tCurso: ".mysqli_result($resultado, $i, "curso")."</br>";
			}
		?>
	</body>
</html>
