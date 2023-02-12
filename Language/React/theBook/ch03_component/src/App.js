import "./App.css";
import React, { Component } from "react";
import MyComponent from "./MyComponent";

/*
class App extends Component{
    render(){
		const name = 'react';
		return <div className="react">{name}</div>
	}
}

*/

// const App = () => {
//     return <MyComponent />;
// };

// const App = () => {
//     return <MyComponent name="React" />;
// };

// const App = () => {
//     return <MyComponent> 리액트 </MyComponent>;
// };

// const App = () => {
//     return <MyComponent name={3}> 리액트 </MyComponent>;
// };

// const App = () => {
//     return <MyComponent name="{3}"> 리액트 </MyComponent>;
// };

// const App = () => {
//     return (
//         <MyComponent name="{3}" favoriteNumber={1}>
//             리액트
//         </MyComponent>
//     );
// };

import Counter from "./Counter";

// const App = () => {
//     return <Counter />;
// };

import Say from "./Say";

const App = () => {
    return <Say />;
};
export default App;
