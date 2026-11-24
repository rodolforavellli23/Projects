--
-- Database: "alunos"
--

-- --------------------------------------------------------

--
-- Table structure for table "alunos"
--

CREATE TABLE alunos (
  ID int(16) NOT NULL,
  nome varchar(50) NOT NULL,
  login varchar(20) NOT NULL,
  senha varchar(12) NOT NULL,
  idade int(3) NOT NULL,
  cidade varchar(50) NOT NULL,
  curso varchar(50) NOT NULL
);

--
-- Dumping data for table "alunos"
--

INSERT INTO alunos (ID, nome, login, senha, idade, cidade, curso) VALUES
(1, 'Eduardo', 'EDU', '123', 20, 'Petrópolis', 'Engenharia'),
(2, 'Roberto', 'ROB', '321', 55, 'Três Rios', 'História'),
(3, 'Valentina', 'VAL', '951', 23, 'Petrópolis', 'Física');

