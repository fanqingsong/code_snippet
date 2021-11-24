from peewee import *
import peeweedbevolve

db = SqliteDatabase('people.db')

class Person(Model):
    name = CharField(null=True)
    birthday = DateField(null=True)
    birthday1 = DateField(null=True)

    class Meta:
        database = db # This model uses the "people.db" database.

class Pet(Model):
    owner = ForeignKeyField(Person, backref='pets')
    name = CharField(null=True)
    animal_type = CharField(null=True)
    animal_type1 = CharField(null=True)

    class Meta:
        database = db # this model uses the "people.db" database

class Pet1(Model):
    owner = ForeignKeyField(Person, backref='pets')
    name = CharField(null=True)
    animal_type = CharField(null=True)

    class Meta:
        database = db # this model uses the "people.db" database


# db.connect()

# db.evolve()
db.create_tables([Person, Pet, Pet1])









