import React, { Component } from "react";

// const MyComponent = () => {
//     return <div>My New Component</div>;
// };

// const MyComponent = (props) => {
//     return (
//         <div>
//             Hello, My Name is {props.name}. <br />
//             children value is {props.children}.
//         </div>
//     );
// };

// const MyComponent = (props) => {
//     const { name, children } = props;

//     return (
//         <div>
//             Hello, My Name is {name}. <br />
//             children value is {children}.
//         </div>
//     );
// };

// const MyComponent = ({ name, children }) => {
//     return (
//         <div>
//             Hello, My Name is {name}. <br />
//             children value is {children}.
//         </div>
//     );
// };

// MyComponent.defaultProps = {
//     name: "Default name",
// };

import PropTypes from "prop-types";

// const MyComponent = ({ name, children }) => {
//     return (
//         <div>
//             Hello, My Name is {name}. <br />
//             children value is {children}.
//         </div>
//     );
// };

// MyComponent.defaultProps = {
//     name: "Default name",
// };

// MyComponent.propTypes = {
//     name: PropTypes.string,
// };

// const MyComponent = ({ name, favoriteNumber, children }) => {
//     return (
//         <div>
//             Hello, My Name is {name}. <br />
//             children value is {children}.<br />
//             My Favorite Number is {favoriteNumber}.
//         </div>
//     );
// };

// MyComponent.defaultProps = {
//     name: "Default name",
// };

// MyComponent.propTypes = {
//     name: PropTypes.string,
//     favoriteNumber: PropTypes.number.isRequired,
// };

// class MyComponent extends Component {
//     render(){
//         const {name, favoriteNumber, children } = this.props;

//         return (
//             <div>
//                 Hello, My Name is {name}. <br />
//                 children value is {children}.<br />
//                 My Favorite Number is {favoriteNumber}.
//             </div>
//         );
//     }
// }

// MyComponent.defaultProps = {
//     name: "Default name",
// };

// MyComponent.propTypes = {
//     name: PropTypes.string,
//     favoriteNumber: PropTypes.number.isRequired,
// };

class MyComponent extends Component {
    static defaultProps={
        name: 'Default name2'
    };
    
    static propTypes = {
        name : PropTypes.string,
        favoriteNumber : PropTypes.number.isRequired
    };

    render(){
        const {name, favoriteNumber, children } = this.props;
        
        return (
            <div>
                Hello, My Name is {name}. <br />
                children value is {children}.<br />
                My Favorite Number is {favoriteNumber}.
            </div>
        );
    }
}

export default MyComponent;
