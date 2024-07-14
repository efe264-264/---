-- MySQL dump 10.13  Distrib 8.0.38, for Win64 (x86_64)
--
-- Host: localhost    Database: game
-- ------------------------------------------------------
-- Server version	8.0.37

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `courses`
--

DROP TABLE IF EXISTS `courses`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `courses` (
  `course_id` int NOT NULL,
  `course_name` varchar(45) NOT NULL,
  `course_credit` int NOT NULL,
  `class_num` int NOT NULL,
  `after_course` varchar(45) NOT NULL,
  `course_class1` varchar(45) NOT NULL,
  `course_class2` varchar(45) NOT NULL,
  `course_class3` varchar(45) NOT NULL,
  `total1` int NOT NULL,
  `total2` int NOT NULL,
  `total3` int NOT NULL,
  `allowance1` int NOT NULL,
  `allowance2` int NOT NULL,
  `allowance3` int NOT NULL,
  PRIMARY KEY (`course_id`),
  UNIQUE KEY `course_id_UNIQUE` (`course_id`),
  UNIQUE KEY `course_name_UNIQUE` (`course_name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `courses`
--

LOCK TABLES `courses` WRITE;
/*!40000 ALTER TABLE `courses` DISABLE KEYS */;
INSERT INTO `courses` VALUES (1,'马克思主义原理',3,2,'5','A1','B1','n',40,40,0,8,40,0),(2,'中国近代史纲要',3,2,'1,12','A6','B6','C6',40,40,0,40,40,0),(3,'毛泽东思想概论',3,2,'1','A7','B7','n',40,40,0,40,40,0),(4,'形势与政策',3,3,'-1','A4','B4','C4',40,40,40,40,40,40),(5,'思想道德与法治',3,2,'-1','A0','B0','n',40,40,40,21,30,39),(6,'习近平思想概论',3,2,'2,3','A8','B8','n',40,40,0,40,40,0),(7,'大学体育',2,3,'-1','A11','B11','C11',40,40,40,40,40,40),(8,'大学英语上',3,3,'-1','A9','B9','C9',40,40,40,40,40,40),(9,'大学英语下',3,3,'8','A10','B10','C10',40,40,40,40,40,40),(10,'军事理论与技能',4,3,'-1','A3','B3','C3',40,40,40,15,36,40),(11,'大学心理',2,2,'5','A2','B2','n',40,40,0,21,32,0),(12,'国家安全教育',1,2,'4,10','A5','B5','n',40,40,0,40,40,0),(13,'高等数学A1',6,3,'-1','A12','B12','C12',40,40,40,40,40,40),(14,'高等数学A2',6,3,'13','A13','B13','C13',40,40,40,40,40,40),(15,'线性代数',3,2,'13','A14','B14','C14',40,40,0,40,40,0),(16,'概率论',3,2,'14','A15','B15','C15',40,40,0,40,40,40),(17,'大学物理B1',4,3,'13','A18','B18','C18',40,40,40,40,40,40),(18,'大学物理B2',4,3,'17','A19','B19','C19',40,40,40,40,40,40),(19,'大学物理实验',2,2,'17','A20','B20','n',40,40,0,40,40,0),(20,'程序设计',4,3,'-1','A23','B23','C23',40,40,40,40,40,40),(21,'计算机科学导论',2,2,'-1','A22','B22','n',40,40,0,40,40,0),(22,'数字逻辑与数字电路',3,2,'21','A25','B25','n',40,40,0,40,40,0),(23,'数据结构',4,2,'21','A24','B24','n',40,40,0,40,40,0),(24,'离散数学',4,3,'14','A16','B16','C16',40,40,40,40,40,40),(25,'计算机组成与体系结构',4,3,'17,23','A27','B27','C27',40,40,40,40,40,40),(26,'操作系统',4,2,'25','A28','B28','n',40,40,0,40,40,0),(27,'计算机网络',3,2,'26','A31','B31','n',40,40,0,40,40,0),(28,'程序语言理论与编译技术',4,3,'25','A29','B29','C29',40,40,40,40,40,40),(29,'微机系统与接口技术',2,1,'22,25','A30','n','n',40,0,0,40,0,0),(30,'算法设计与分析',4,2,'30','A32','B32','n',40,40,0,40,40,0),(31,' 机器学习',3,2,'28','A33','B33','n',40,40,0,40,40,0),(32,'现代数据库系统',4,3,'27,30','A34','B34','C34',40,40,40,40,40,40),(33,'计算机科学理论与方法',3,3,'32','A35','B35','C35',40,40,40,40,40,40),(34,'网络安全',3,2,'38','A37','B37','n',40,40,0,40,40,0),(35,'计算机系统基础',2,2,'21','A26','B26','n',40,40,0,40,40,0),(36,'软件构造基础',2,1,'40','A39','n39','n',40,0,0,40,0,0),(37,'数字信号处理',2,1,'16,23','A17','n','n',40,0,0,40,0,0),(38,'人工智能前沿与交叉',2,2,'31','A36','B36','n',40,40,0,40,40,0),(39,'量子信息与量子计算基础',2,1,'18','A21','n','n',40,0,0,40,0,0),(40,'软件导论',1,1,'20','A38','n38','n',40,0,0,40,0,0);
/*!40000 ALTER TABLE `courses` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `log`
--

DROP TABLE IF EXISTS `log`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `log` (
  `id` varchar(45) NOT NULL,
  `pw` varchar(45) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `log`
--

LOCK TABLES `log` WRITE;
/*!40000 ALTER TABLE `log` DISABLE KEYS */;
INSERT INTO `log` VALUES ('2023302101001','58E29O'),('2023302111001','58E29O'),('2023302111002','990AHd  '),('2023302111003','aB3c4D'),('2023302111004','Z7xY6g  '),('2023302111005','h2J3K4  '),('2023302111006','L9sT8U'),('2023302111007','Q4w3E2'),('2023302111008','r5T6y7'),('2023302111009','F2D3e4'),('2023302111010','v8B7N6  '),('2023302111011','C5x4Z3'),('2023302111012','G9H8j7'),('2023302111013','m2N3B4  '),('2023302111014','p0Q9R8'),('2023302111015','S7V6t5'),('2023302111016','w3E2r1'),('2023302111017','Y6X5C4  '),('2023302111018','k9L8J7'),('2023302111019','Z2A1s0'),('2023302111020','d3F2g1'),('2023302111021','H7G6f5'),('2023302111022','J4k3L2'),('2023302111023','N6M5b4  '),('2023302111024','Q8w7e6'),('2023302111025','t5R4S3'),('2023302111026','x2C1v0'),('2023302111027','B3V2G1'),('2023302111028','E4D3c2'),('2023302111029','f5T4r3'),('2023302111030','g6S5p4'),('2023302111031','h7U6o5 '),('2023302111032','i8V7n6'),('2023302111033','j9W8m7'),('2023302111034','k0X9l8'),('2023302111035','l1Y0a2'),('2023302111036','m2Z1b0'),('2023302111037','n3A2c1'),('2023302111038','o4B3d2  '),('2023302111039','p5C4e3'),('2023302111040','q6D5f4');
/*!40000 ALTER TABLE `log` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `students`
--

DROP TABLE IF EXISTS `students`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `students` (
  `student_id` int NOT NULL,
  `student_name` varchar(500) NOT NULL,
  `course_class1` varchar(500) NOT NULL,
  `course_class2` varchar(500) NOT NULL,
  `course_class3` varchar(500) NOT NULL,
  `course_class4` varchar(500) NOT NULL,
  `course_class5` varchar(500) NOT NULL,
  `course_class6` varchar(500) NOT NULL,
  `course_class7` varchar(500) NOT NULL,
  `course_class8` varchar(500) NOT NULL,
  PRIMARY KEY (`student_id`),
  UNIQUE KEY `student_id_UNIQUE` (`student_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `students`
--

LOCK TABLES `students` WRITE;
/*!40000 ALTER TABLE `students` DISABLE KEYS */;
INSERT INTO `students` VALUES (3,'lily','math1,computer1,math1,computer1,math1,computer1,math2,computer1,math2,computer1,math2,computer1,','csapp1,data1,csapp1,data1,csapp1,data1,csapp2,data1,csapp2,data1,csapp2,data1,','cg1,cg1,cg1,cg1,cg1,cg2,','n','n','n','n','n');
/*!40000 ALTER TABLE `students` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `topresult`
--

DROP TABLE IF EXISTS `topresult`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `topresult` (
  `result1` varchar(500) NOT NULL,
  `result2` varchar(500) NOT NULL,
  `result3` varchar(500) NOT NULL,
  `result4` varchar(500) NOT NULL,
  PRIMARY KEY (`result1`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `topresult`
--

LOCK TABLES `topresult` WRITE;
/*!40000 ALTER TABLE `topresult` DISABLE KEYS */;
INSERT INTO `topresult` VALUES ('n','n','n','n');
/*!40000 ALTER TABLE `topresult` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-07-12 21:38:11
