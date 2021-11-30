from sqlalchemy import Column,Integer,String,create_engine,Text
from sqlalchemy.orm import sessionmaker
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()

class User(Base):
    __tablename__ ='user'

    id = Column(Integer,primary_key=True)   
    username = Column(String(20),nullable=False, default="")   
    password = Column(String(100),nullable=False, default="")


class Article(Base):
    __tablename__ ='article'

    id = Column(Integer,primary_key=True)   
    title = Column(String(100),nullable=False, default="")   
    content = Column(Text, nullable=False, default="")
    # content1 = Column(Text, nullable=False, server_default="")




