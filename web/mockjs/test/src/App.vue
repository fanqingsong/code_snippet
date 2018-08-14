<template>
  <div id="app">
    girls info:
    <div>name: {{girl_props.name}}</div>
    <div>age: {{girl_props.age}}</div>
    <div>color: {{girl_props.color}}</div>

    <hr>
    <button @click="addpost">add new post</button>
    her posts json:
    <div>
      <ul>
        <li v-for="post of posts">{{post.title}}</li>
      </ul>
    </div>
  </div>
</template>

<script>
import data from '../utils/mock';

import axios from 'axios';

import HelloWorld from './components/HelloWorld'

export default {
  name: 'App',
  components: {
    HelloWorld
  },
  data(){
    return {
      girl_props: {},
      posts: [],
      errors: []
    }
  },
  methods:{
    addpost: function(){
      axios.post('http://localhost:3000/posts', {
        title: "a new title birthed."
      })
      .then(response => {
        axios.get('http://localhost:3000/posts')
        .then(response => {
          this.posts = response.data
        })
      })
      .catch(e => {
        this.errors.push(e)
      })
    }
  },
  created: function(){
    axios.get('http://g.cn')
    .then(response => {
      // JSON responses are automatically parsed.
      this.girl_props = response.data
      console.log(response.data);
    })
    .catch(e => {
      this.errors.push(e)
    })

    axios.get('http://localhost:3000/posts')
    .then(response => {
      // JSON responses are automatically parsed.
      this.posts = response.data
      console.log(response.data);
    })
    .catch(e => {
      this.errors.push(e)
    })

  }
}
</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
