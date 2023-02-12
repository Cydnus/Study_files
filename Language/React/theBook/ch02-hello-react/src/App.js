import logo from "./logo.svg";
import "./App.css";

/*
function App() {
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          Edit <code>src/App.js</code> and save to reload.
        </p>
        <a
          className="App-link"
          href="https://reactjs.org"
          target="_blank"
          rel="noopener noreferrer"
        >
          Learn React
        </a>
      </header>
    </div>
  );
}
*/

/*
function App()
{
  return (
    <div> 
      Hello <b>React</b>
    </div>
  );
}
*/

/*
function App()
{
  return (
    <> 
      <h1>Hello</h1>
      <h2>React</h2>
    </>
  );
}
*/

/*
function App()
{
  const name = "React_name";
  return (
    <> 
      <h1>Hello</h1>
      <h2>{name}</h2>
    </>
  );
}
*/

/*
function App()
{
  const name = "React1";
  return (
    <> 
    {name =='React'? 
    <h1> isReact:True </h1>
    :<h2> isReact:False </h2>}
    </>
  );
}
*/

/*
function App()
{
  const name = undefined;
  return name;
}
*/

/*
function App()
{
  const name = undefined;
  return <div>{name||'React'}</div>;
}
*/

/*
function App()
{
  const name = 'React';
  const style = {
    backgroundColor : 'black',
    color:'aqua',
    fontSize: '48px',
    fontWeight:'bold',
    padding:16
  };
  return <div style={style}>{name}</div>;
}
*/

/*
function App()
{
  const name = 'React';
  return <div style={{
    backgroundColor : 'black',
    color:'aqua',
    fontSize: '48px',
    fontWeight:'bold',
    padding:16
  }}>{name}</div>;
}
*/

/*
function App()
{
  const name = 'React';
  return <div className="react">{name}</div>;
}
*/

/*
function App()
{
  const name = 'React';
  return (
  <>
    <div className="react">{name}</div>
    <input />
  </>
  );
}
*/

// function App()
// {
//   const name = 'React';
//   return (
//   <>
//     {/* 주석작성 */}
//     <div
//     className="react" // 시작태그 여러줄일 경우 여기에 작성가능
//     >
//       {name}
//       </div>

//       // 하지만 이런 주석이나
//       /* 이런 주석은 그대로 나타남 */

//     <input />
//   </>
//   );
// }

function App() {
  const name = "리액트";
  return (
    <div>
      <div className="react">{name}</div>
      <h1>들여쓰기가 이상한</h1>
      <h2>코드</h2>
      <p>입니다.</p>
    </div>
  );
}

export default App;
