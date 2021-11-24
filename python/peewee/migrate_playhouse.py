from playhouse.migrate import *


my_db = SqliteDatabase('people.db')
migrator = SqliteMigrator(my_db)


title_field = CharField(default='')
status_field = IntegerField(null=True)

migrate(
    migrator.add_column('person', 'title', title_field),
)




