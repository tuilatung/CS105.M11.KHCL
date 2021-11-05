/*
    Họ tên: Huỳnh Thiện Tùng
    MSSV:   19522492
    LAB:    06

*/

function init() {
    var scene = new THREE.Scene();
    var gui = new dat.GUI();
    var clock = new THREE.Clock();

    

    var camera = new THREE.PerspectiveCamera(
        45,
        window.innerWidth/window.innerHeight,
        1, 
        1000
    );

    
    var renderer = new THREE.WebGLRenderer();
    renderer.shadowMap.enabled = true;
    renderer.setSize(window.innerWidth, window.innerHeight);
    renderer.setClearColor('rgb(120, 120, 120)');
    document.getElementById('webgl').appendChild(renderer.domElement)
    
    var controls = new THREE.OrbitControls(camera, renderer.domElement);

    update( renderer, scene, camera, controls );
    return scene;
}


function update( renderer, scene, camera, controls, clock ) {
    renderer.render(
        scene,
        camera
    );
    controls.update();


    requestAnimationFrame(function() {
        update( renderer, scene, camera, controls, clock );
    });
}

var scene = init();
