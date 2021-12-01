from sqlalchemy import Column, String, create_engine
from models_definition import Base


# 初始化数据库连接:
# engine = create_engine('sqlite:///test.db')
engine = create_engine('mysql+mysqldb://root:root@localhost/playground')

Base.metadata.create_all(engine)

