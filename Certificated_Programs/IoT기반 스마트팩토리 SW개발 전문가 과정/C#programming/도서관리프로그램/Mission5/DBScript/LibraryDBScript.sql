
--USE [Library]
--GO
--ALTER TABLE [dbo].[CheckOut] DROP CONSTRAINT [FK_CheckOut_Member]
--GO
--ALTER TABLE [dbo].[CheckOut] DROP CONSTRAINT [FK_CheckOut_Librarian]
--GO
--ALTER TABLE [dbo].[CheckOut] DROP CONSTRAINT [FK_CheckOut_BookCopy]
--GO
--ALTER TABLE [dbo].[BookCopy] DROP CONSTRAINT [FK_BookCopy_Book]
--GO
--/****** Object:  Table [dbo].[Rule]    Script Date: 2017-02-09 오전 9:08:37 ******/
--DROP TABLE [dbo].[Rule]
--GO
--/****** Object:  Table [dbo].[Member]    Script Date: 2017-02-09 오전 9:08:37 ******/
--DROP TABLE [dbo].[Member]
--GO
--/****** Object:  Table [dbo].[Librarian]    Script Date: 2017-02-09 오전 9:08:37 ******/
--DROP TABLE [dbo].[Librarian]
--GO
--/****** Object:  Table [dbo].[CheckOut]    Script Date: 2017-02-09 오전 9:08:37 ******/
--DROP TABLE [dbo].[CheckOut]
--GO
--/****** Object:  Table [dbo].[BookCopy]    Script Date: 2017-02-09 오전 9:08:37 ******/
--DROP TABLE [dbo].[BookCopy]
--GO
--/****** Object:  Table [dbo].[Book]    Script Date: 2017-02-09 오전 9:08:37 ******/
--DROP TABLE [dbo].[Book]
--GO
--USE [master]
--GO
--/****** Object:  Database [Library]    Script Date: 2017-02-09 오전 9:08:37 ******/
--DROP DATABASE [Library]
--GO

--/****** Object:  Database [Library]    Script Date: 2017-02-09 오전 9:08:37 ******/

--CREATE DATABASE [Library]
-- CONTAINMENT = NONE
-- ON  PRIMARY 
--( NAME = N'Library', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL12.SQLEXPRESS\MSSQL\DATA\Library.mdf' , SIZE = 5120KB , MAXSIZE = UNLIMITED, FILEGROWTH = 1024KB )
-- LOG ON 
--( NAME = N'Library_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL12.SQLEXPRESS\MSSQL\DATA\Library_log.ldf' , SIZE = 1024KB , MAXSIZE = 2048GB , FILEGROWTH = 10%)
--GO
--ALTER DATABASE [Library] SET COMPATIBILITY_LEVEL = 120
--GO
--IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
--begin
--EXEC [Library].[dbo].[sp_fulltext_database] @action = 'enable'
--end
--GO
--ALTER DATABASE [Library] SET ANSI_NULL_DEFAULT OFF 
--GO
--ALTER DATABASE [Library] SET ANSI_NULLS OFF 
--GO
--ALTER DATABASE [Library] SET ANSI_PADDING OFF 
--GO
--ALTER DATABASE [Library] SET ANSI_WARNINGS OFF 
--GO
--ALTER DATABASE [Library] SET ARITHABORT OFF 
--GO
--ALTER DATABASE [Library] SET AUTO_CLOSE OFF 
--GO
--ALTER DATABASE [Library] SET AUTO_SHRINK OFF 
--GO
--ALTER DATABASE [Library] SET AUTO_UPDATE_STATISTICS ON 
--GO
--ALTER DATABASE [Library] SET CURSOR_CLOSE_ON_COMMIT OFF 
--GO
--ALTER DATABASE [Library] SET CURSOR_DEFAULT  GLOBAL 
--GO
--ALTER DATABASE [Library] SET CONCAT_NULL_YIELDS_NULL OFF 
--GO
--ALTER DATABASE [Library] SET NUMERIC_ROUNDABORT OFF 
--GO
--ALTER DATABASE [Library] SET QUOTED_IDENTIFIER OFF 
--GO
--ALTER DATABASE [Library] SET RECURSIVE_TRIGGERS OFF 
--GO
--ALTER DATABASE [Library] SET  DISABLE_BROKER 
--GO
--ALTER DATABASE [Library] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
--GO
--ALTER DATABASE [Library] SET DATE_CORRELATION_OPTIMIZATION OFF 
--GO
--ALTER DATABASE [Library] SET TRUSTWORTHY OFF 
--GO
--ALTER DATABASE [Library] SET ALLOW_SNAPSHOT_ISOLATION OFF 
--GO
--ALTER DATABASE [Library] SET PARAMETERIZATION SIMPLE 
--GO
--ALTER DATABASE [Library] SET READ_COMMITTED_SNAPSHOT OFF 
--GO
--ALTER DATABASE [Library] SET HONOR_BROKER_PRIORITY OFF 
--GO
--ALTER DATABASE [Library] SET RECOVERY SIMPLE 
--GO
--ALTER DATABASE [Library] SET  MULTI_USER 
--GO
--ALTER DATABASE [Library] SET PAGE_VERIFY CHECKSUM  
--GO
--ALTER DATABASE [Library] SET DB_CHAINING OFF 
--GO
--ALTER DATABASE [Library] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
--GO
--ALTER DATABASE [Library] SET TARGET_RECOVERY_TIME = 0 SECONDS 
--GO
--ALTER DATABASE [Library] SET DELAYED_DURABILITY = DISABLED 
--GO
--USE [Library]
--GO
--/****** Object:  Table [dbo].[Book]    Script Date: 2017-02-09 오전 9:08:37 ******/
--SET ANSI_NULLS ON
--GO
--SET QUOTED_IDENTIFIER ON
--GO

CREATE TABLE [dbo].[Book](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[BookCode] [nvarchar](6) NULL,
	[Title] [nvarchar](50) NOT NULL,
	[Publisher] [nvarchar](20) NOT NULL,
	[PublishDate] [datetime] NOT NULL,
	[Author] [nvarchar](20) NOT NULL,
 CONSTRAINT [PK_Book] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[BookCopy]    Script Date: 2017-02-09 오전 9:08:37 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[BookCopy](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[BookId] [int] NOT NULL,
	[BookCopyCode] [nvarchar](9) NOT NULL,
	[BookStatus] [int] NOT NULL,
	[ArrivalDate] [datetime] NOT NULL,
 CONSTRAINT [PK_BookCopy] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[CheckOut]    Script Date: 2017-02-09 오전 9:08:37 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[CheckOut](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[MemberId] [int] NOT NULL,
	[BookCopyId] [int] NOT NULL,
	[CheckOutDate] [datetime] NOT NULL,
	[DueDate] [datetime] NOT NULL,
	[ReturnDate] [datetime] NULL,
	[OverdueDays] [int] NULL,
	[OverdueCharge] [int] NULL,
	[LibrarianId] [int] NOT NULL,
 CONSTRAINT [PK_CheckOut] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Librarian]    Script Date: 2017-02-09 오전 9:08:37 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Librarian](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[LoginId] [nvarchar](20) NOT NULL,
	[Password] [nvarchar](20) NOT NULL,
	[PhoneNo] [nvarchar](15) NOT NULL,
	[Status] [int] NOT NULL,
	[Name] [nvarchar](20) NOT NULL,
 CONSTRAINT [PK_Librarian] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Member]    Script Date: 2017-02-09 오전 9:08:37 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Member](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[LoginId] [nvarchar](20) NOT NULL,
	[Password] [nvarchar](20) NOT NULL,
	[Name] [nvarchar](20) NOT NULL,
	[MemberLevel] [int] NOT NULL,
	[Address] [nvarchar](50) NOT NULL,
	[PhoneNo] [nvarchar](15) NOT NULL,
	[RegisterDate] [datetime] NOT NULL,
 CONSTRAINT [PK_Member] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Rule]    Script Date: 2017-02-09 오전 9:08:37 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Rule](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[LateFeePerDay] [int] NOT NULL,
	[NumOfBooksCanCheckOut] [int] NOT NULL,
	[RentDays] [int] NOT NULL,
 CONSTRAINT [PK_Rule] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET IDENTITY_INSERT [dbo].[Book] ON 

GO
INSERT [dbo].[Book] ([Id], [BookCode], [Title], [Publisher], [PublishDate], [Author]) VALUES (2, N'100001', N'C# 정복', N'햇님출판사', CAST(N'2014-05-03T00:00:00.000' AS DateTime), N'홍길동')
GO
INSERT [dbo].[Book] ([Id], [BookCode], [Title], [Publisher], [PublishDate], [Author]) VALUES (3, N'100002', N'Java 길라잡이', N'하나출판사', CAST(N'2016-04-01T00:00:00.000' AS DateTime), N'나자바')
GO
INSERT [dbo].[Book] ([Id], [BookCode], [Title], [Publisher], [PublishDate], [Author]) VALUES (4, N'100003', N'직업상담사', N'에듀윌', CAST(N'2013-06-21T00:00:00.000' AS DateTime), N'정옥경')
GO
SET IDENTITY_INSERT [dbo].[Book] OFF
GO
SET IDENTITY_INSERT [dbo].[BookCopy] ON 

GO
INSERT [dbo].[BookCopy] ([Id], [BookId], [BookCopyCode], [BookStatus], [ArrivalDate]) VALUES (1, 2, N'100001001', 1, CAST(N'2014-01-01T00:00:00.000' AS DateTime))
GO
INSERT [dbo].[BookCopy] ([Id], [BookId], [BookCopyCode], [BookStatus], [ArrivalDate]) VALUES (2, 2, N'100001002', 0, CAST(N'2014-01-01T00:00:00.000' AS DateTime))
GO
INSERT [dbo].[BookCopy] ([Id], [BookId], [BookCopyCode], [BookStatus], [ArrivalDate]) VALUES (3, 3, N'100002001', 1, CAST(N'2015-05-05T00:00:00.000' AS DateTime))
GO
INSERT [dbo].[BookCopy] ([Id], [BookId], [BookCopyCode], [BookStatus], [ArrivalDate]) VALUES (4, 3, N'100002002', 0, CAST(N'2015-05-05T00:00:00.000' AS DateTime))
GO
INSERT [dbo].[BookCopy] ([Id], [BookId], [BookCopyCode], [BookStatus], [ArrivalDate]) VALUES (5, 4, N'100003001', 0, CAST(N'2016-09-09T00:00:00.000' AS DateTime))
GO
SET IDENTITY_INSERT [dbo].[BookCopy] OFF
GO
SET IDENTITY_INSERT [dbo].[CheckOut] ON 

GO
INSERT [dbo].[CheckOut] ([Id], [MemberId], [BookCopyId], [CheckOutDate], [DueDate], [ReturnDate], [OverdueDays], [OverdueCharge], [LibrarianId]) VALUES (1, 2, 3, CAST(N'2017-02-09T00:24:50.590' AS DateTime), CAST(N'2017-02-24T00:00:00.000' AS DateTime), CAST(N'2017-02-09T01:35:40.687' AS DateTime), 0, 0, 1)
GO
INSERT [dbo].[CheckOut] ([Id], [MemberId], [BookCopyId], [CheckOutDate], [DueDate], [ReturnDate], [OverdueDays], [OverdueCharge], [LibrarianId]) VALUES (2, 2, 1, CAST(N'2017-02-09T00:35:44.033' AS DateTime), CAST(N'2017-02-24T00:00:00.000' AS DateTime), CAST(N'2017-02-09T01:43:52.157' AS DateTime), 0, 0, 1)
GO
INSERT [dbo].[CheckOut] ([Id], [MemberId], [BookCopyId], [CheckOutDate], [DueDate], [ReturnDate], [OverdueDays], [OverdueCharge], [LibrarianId]) VALUES (3, 2, 1, CAST(N'2017-02-09T02:08:57.510' AS DateTime), CAST(N'2017-02-24T00:00:00.000' AS DateTime), CAST(N'2017-02-09T02:09:07.257' AS DateTime), 0, 0, 1)
GO
INSERT [dbo].[CheckOut] ([Id], [MemberId], [BookCopyId], [CheckOutDate], [DueDate], [ReturnDate], [OverdueDays], [OverdueCharge], [LibrarianId]) VALUES (4, 2, 1, CAST(N'2017-02-09T02:09:04.730' AS DateTime), CAST(N'2017-02-24T00:00:00.000' AS DateTime), CAST(N'2017-02-09T02:09:07.970' AS DateTime), 0, 0, 1)
GO
INSERT [dbo].[CheckOut] ([Id], [MemberId], [BookCopyId], [CheckOutDate], [DueDate], [ReturnDate], [OverdueDays], [OverdueCharge], [LibrarianId]) VALUES (5, 2, 1, CAST(N'2017-02-09T02:09:12.663' AS DateTime), CAST(N'2017-02-24T00:00:00.000' AS DateTime), CAST(N'2017-02-09T02:21:27.807' AS DateTime), 0, 0, 1)
GO
INSERT [dbo].[CheckOut] ([Id], [MemberId], [BookCopyId], [CheckOutDate], [DueDate], [ReturnDate], [OverdueDays], [OverdueCharge], [LibrarianId]) VALUES (6, 2, 4, CAST(N'2017-02-09T02:19:07.080' AS DateTime), CAST(N'2017-02-24T00:00:00.000' AS DateTime), CAST(N'2017-02-09T02:21:26.660' AS DateTime), 0, 0, 1)
GO
INSERT [dbo].[CheckOut] ([Id], [MemberId], [BookCopyId], [CheckOutDate], [DueDate], [ReturnDate], [OverdueDays], [OverdueCharge], [LibrarianId]) VALUES (7, 2, 4, CAST(N'2017-02-09T02:19:13.677' AS DateTime), CAST(N'2017-02-24T00:00:00.000' AS DateTime), CAST(N'2017-02-09T02:19:20.900' AS DateTime), 0, 0, 1)
GO
INSERT [dbo].[CheckOut] ([Id], [MemberId], [BookCopyId], [CheckOutDate], [DueDate], [ReturnDate], [OverdueDays], [OverdueCharge], [LibrarianId]) VALUES (8, 2, 1, CAST(N'2017-02-09T02:23:09.397' AS DateTime), CAST(N'2017-02-24T00:00:00.000' AS DateTime), CAST(N'2017-02-09T02:23:11.083' AS DateTime), 0, 0, 1)
GO
INSERT [dbo].[CheckOut] ([Id], [MemberId], [BookCopyId], [CheckOutDate], [DueDate], [ReturnDate], [OverdueDays], [OverdueCharge], [LibrarianId]) VALUES (9, 2, 1, CAST(N'2017-02-09T02:23:12.007' AS DateTime), CAST(N'2017-02-24T00:00:00.000' AS DateTime), CAST(N'2017-02-09T02:29:21.590' AS DateTime), 0, 0, 1)
GO
INSERT [dbo].[CheckOut] ([Id], [MemberId], [BookCopyId], [CheckOutDate], [DueDate], [ReturnDate], [OverdueDays], [OverdueCharge], [LibrarianId]) VALUES (10, 2, 1, CAST(N'2017-02-09T02:23:14.623' AS DateTime), CAST(N'2017-02-24T00:00:00.000' AS DateTime), CAST(N'2017-02-09T02:27:05.323' AS DateTime), 0, 0, 1)
GO
INSERT [dbo].[CheckOut] ([Id], [MemberId], [BookCopyId], [CheckOutDate], [DueDate], [ReturnDate], [OverdueDays], [OverdueCharge], [LibrarianId]) VALUES (11, 2, 1, CAST(N'2017-02-09T02:31:29.647' AS DateTime), CAST(N'2017-02-24T00:00:00.000' AS DateTime), CAST(N'2017-02-09T02:31:32.553' AS DateTime), 0, 0, 1)
GO
INSERT [dbo].[CheckOut] ([Id], [MemberId], [BookCopyId], [CheckOutDate], [DueDate], [ReturnDate], [OverdueDays], [OverdueCharge], [LibrarianId]) VALUES (12, 2, 1, CAST(N'2017-02-09T02:31:39.913' AS DateTime), CAST(N'2017-02-24T00:00:00.000' AS DateTime), CAST(N'2017-02-09T02:31:45.757' AS DateTime), 0, 0, 1)
GO
INSERT [dbo].[CheckOut] ([Id], [MemberId], [BookCopyId], [CheckOutDate], [DueDate], [ReturnDate], [OverdueDays], [OverdueCharge], [LibrarianId]) VALUES (13, 2, 1, CAST(N'2017-02-09T02:31:49.573' AS DateTime), CAST(N'2017-02-24T00:00:00.000' AS DateTime), NULL, NULL, NULL, 1)
GO
INSERT [dbo].[CheckOut] ([Id], [MemberId], [BookCopyId], [CheckOutDate], [DueDate], [ReturnDate], [OverdueDays], [OverdueCharge], [LibrarianId]) VALUES (14, 2, 3, CAST(N'2017-02-09T02:38:01.527' AS DateTime), CAST(N'2017-02-16T00:00:00.000' AS DateTime), NULL, NULL, NULL, 1)
GO
INSERT [dbo].[CheckOut] ([Id], [MemberId], [BookCopyId], [CheckOutDate], [DueDate], [ReturnDate], [OverdueDays], [OverdueCharge], [LibrarianId]) VALUES (15, 2, 5, CAST(N'2017-02-09T02:38:11.237' AS DateTime), CAST(N'2017-02-16T00:00:00.000' AS DateTime), CAST(N'2017-02-09T02:38:15.713' AS DateTime), 0, 0, 1)
GO
SET IDENTITY_INSERT [dbo].[CheckOut] OFF
GO
SET IDENTITY_INSERT [dbo].[Librarian] ON 

GO
INSERT [dbo].[Librarian] ([Id], [LoginId], [Password], [PhoneNo], [Status], [Name]) VALUES (1, N'happy', N'1234', N'010-3432-1432', 0, N'나사서')
GO
SET IDENTITY_INSERT [dbo].[Librarian] OFF
GO
SET IDENTITY_INSERT [dbo].[Member] ON 

GO
INSERT [dbo].[Member] ([Id], [LoginId], [Password], [Name], [MemberLevel], [Address], [PhoneNo], [RegisterDate]) VALUES (2, N'10001', N'10001', N'이순신', 0, N'인천 서구 마전동', N'010-8211-6930', CAST(N'2016-05-07T00:00:00.000' AS DateTime))
GO
SET IDENTITY_INSERT [dbo].[Member] OFF
GO
SET IDENTITY_INSERT [dbo].[Rule] ON 

GO
INSERT [dbo].[Rule] ([Id], [LateFeePerDay], [NumOfBooksCanCheckOut], [RentDays]) VALUES (1, 200, 3, 7)
GO
SET IDENTITY_INSERT [dbo].[Rule] OFF
GO
ALTER TABLE [dbo].[BookCopy]  WITH CHECK ADD  CONSTRAINT [FK_BookCopy_Book] FOREIGN KEY([BookId])
REFERENCES [dbo].[Book] ([Id])
GO
ALTER TABLE [dbo].[BookCopy] CHECK CONSTRAINT [FK_BookCopy_Book]
GO
ALTER TABLE [dbo].[CheckOut]  WITH CHECK ADD  CONSTRAINT [FK_CheckOut_BookCopy] FOREIGN KEY([BookCopyId])
REFERENCES [dbo].[BookCopy] ([Id])
GO
ALTER TABLE [dbo].[CheckOut] CHECK CONSTRAINT [FK_CheckOut_BookCopy]
GO
ALTER TABLE [dbo].[CheckOut]  WITH CHECK ADD  CONSTRAINT [FK_CheckOut_Librarian] FOREIGN KEY([LibrarianId])
REFERENCES [dbo].[Librarian] ([Id])
GO
ALTER TABLE [dbo].[CheckOut] CHECK CONSTRAINT [FK_CheckOut_Librarian]
GO
ALTER TABLE [dbo].[CheckOut]  WITH CHECK ADD  CONSTRAINT [FK_CheckOut_Member] FOREIGN KEY([MemberId])
REFERENCES [dbo].[Member] ([Id])
GO
ALTER TABLE [dbo].[CheckOut] CHECK CONSTRAINT [FK_CheckOut_Member]
GO
USE [master]
GO
ALTER DATABASE [Library] SET  READ_WRITE 
GO
